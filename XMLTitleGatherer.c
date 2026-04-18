#include <stdio.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
//test1
void printTitles(xmlNodePtr cur){
	xmlNodePtr child;
	if (xmlStrcmp(cur->name, (const xmlChar *) "catalog")) {
		printf("document of the wrong type, root node != catalog");
		return;
	}

	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
		child = cur->children;
		
		while (child != NULL) {
			if ((!xmlStrcmp(child->name, (const xmlChar *)"title"))){
				xmlChar *title = xmlNodeGetContent(child);
				printf("title: %s\n", title);
				xmlFree(title);
				break;
			}

			child = child->next;
		} 
		cur = cur->next;
	}
}

int main(int argc, char *argv[]) {
	xmlDocPtr doc;
	xmlNodePtr cur;
	
	if (argc != 2) {
		printf("Usage: %s <xml_file>\n", argv[0]);
		return 1;
	}

	doc = xmlParseFile(argv[1]); 
	if (doc == NULL) {
		printf("failed to parse XML File\n");
		return 1;
	}
	
	cur = xmlDocGetRootElement(doc);
	
	if (cur == NULL) {
		printf("empty document\n");
	}

	printTitles(cur);
	
	xmlFreeDoc(doc);
	xmlCleanupParser();

	return 0;
    }


#include "practice.c"


int main() {
   printStyles();
   unsigned int table[LENGTH];
   unsigned char *text = "Never gonna give you up. Never Gonna let you down!";

   frequenceTableInit(table);
   frequenceTableFill(table, text);
   frequenceTablePrint(table);

   List list;
   listInit(&list);
   listFill(&list,table);
   listPrint(&list);

   Node *root = HuffmanTreeInsert(&list);
   HuffmanTreePrint(root, 0);

   int cols = maximumDepth(root);
   char **dictionary = dictionaryInit(cols);
   createDictionary(dictionary, root, "", cols);
   dictionaryPrint(dictionary);

   char *code = encode(dictionary, text);   
   printf("\nCode: %s\n", code);

   char *decode = toDecode(text, root, code);
   printf("\nDecode: %s\n", decode);

   return 0;
}
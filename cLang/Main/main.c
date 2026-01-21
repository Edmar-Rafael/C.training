#include "practice.c"
#define E "\U0001f600"


int main() {
   printStyles();

   int choice;
   char str[10];
   char *opt = "0 - Exit"E"\n1 - Insert at begin\n2 - Remove at begin\n3 - Print\n4 - Sort\n";
   char *opt2 = "5 - To invert\n6 - Clear list\n7 - Insert at end\n8 - Remove at end\n";
   char *opt3 = "9 - Change Elements\n10 - Insert at specific pos\n11 - Remove specific element\n";

   List list;
   Node *remove;

   createList(&list);

   while(1) {
      printf("%s%s%s\n", opt, opt2, opt3);
      scanf("%s", str);

      if(charToInt(str) || *str == '0') {
         choice = charToInt(str);
         getchar();
         
         switch(choice) {
            case 1: {
               push(&list, str);
               continue;
            }
            case 2: {
               remove = pop(&list);
               remove ? printf("{%d} removed.\n\n", remove->data) : printf("Nothing to remove.\n\n");
               continue;
            }
            case 3: {
               printList(list);
               continue;
            }
            case 4: {
               SortList(&list);
               continue;
            }
            case 5: {
               listInverter(&list);
               continue;
            }
            case 6: {
               clearList(&list);
               continue;
            }
            case 7: {
               enqueue(&list, str);
               continue;
            }
            case 8: {
               remove = dequeue(&list);
               remove ? printf("{%d} removed!\n\n", remove->data) : printf("Nothing to remove!\n\n");
               continue;
            }
            case 9: {
               changePlace(&list, 0, 0);
               continue;
            }
            case 10: {
               pushAtSpecificElement(&list, 0, str);
               continue;
            }
            case 11: {
               remove = popAtspecificPos(&list, 0);
               remove ? printf("{%d} removed.\n\n", remove->data) : printf("Nothing to remove.\n\n");
               continue;
            }
            default: {
               if(choice != 0) {
                  Error(str);
                  continue;
               }

               printf("Good bye!\n\n");
               return 0;
            }
         }
      }

      catch();
      continue;
   }

   return 0;
}

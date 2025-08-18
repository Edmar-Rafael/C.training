#include "practice.c"


int main() {
   printStyles();

   unsigned int table[LENGTH] = {0};
   unsigned char *text = "Well! At least I think I should try it.";

   frequenceTableFill(table, text);
   frequenceTablePrint(table);

   List list;

   listInit(&list);
   listFill(&list, table);
   listPrint(list);

   Stack stk;
   stackInit(&stk);

   Node *root = HuffmanTreeInsert(&list);
   iterativeStackTreePrint(&stk, root);

   int cols = iterativeMaximumDepth(&stk, root);

   char **dictionary = dictionaryInit(cols);

   iterativeCreateDictionary(dictionary, root, &stk, cols);
   dictionaryPrint(dictionary);

   char *code = encode(dictionary, text);
   printf("\ncode: %s\n", code);

   char *decoded = toDecode(code, root, text);
   printf("\ndecode: %s\n", decoded);

   return 0;
}
/*
y:1->u:1->r:1->o:1->n:1->k:1->d:1->a:1->W:1->A:1->.:1->!:1->s:2->i:2->h:2->e:2->I:2->l:4->t:5->'':8->
                              +:2
                             /   \
                            y     u
->r:1->o:1->n:1->k:1->d:1->a:1->W:1->A:1->.:1->!:1->+:2-> s:2->i:2->h:2->e:2->I:2->l:4->t:5->'':8->
                              +:2
                             /   \
                            r     o
->n:1->k:1->d:1->a:1->W:1->A:1->.:1->!:1->+:2 ->+:2-> s:2->i:2->h:2->e:2->I:2->l:4->t:5->'':8->
                              +:2
                             /   \
                            n     k
->d:1->a:1->W:1->A:1->.:1->!:1->+:2-> +:2 ->+:2-> s:2->i:2->h:2->e:2->I:2->l:4->t:5->'':8->
                              +:2
                             /   \
                            d     a
->W:1->A:1->.:1->!:1->+:2-> +:2 ->+:2 ->+:2-> s:2->i:2->h:2->e:2->I:2->l:4->t:5->'':8->
                              +:2
                             /   \
                            W     A
->.:1->!:1->+:2 ->+:2-> +:2 ->+:2 ->+:2-> s:2->i:2->h:2->e:2->I:2->l:4->t:5->'':8->
                              +:2
                             /   \
                            .     !
->+:2 ->+:2 ->+:2-> +:2 ->+:2 ->+:2-> s:2->i:2->h:2->e:2->I:2->l:4->t:5->'':8->
                              +:4
                          /         \
                        +:2         +:2
                       /   \       /   \
                      .     !     W     A
->+:2-> +:2 ->+:2 ->+:2-> s:2->i:2->h:2->e:2->I:2->+:4 ->l:4->t:5->'':8->
                              +:4
                           /        \
                         +:2        +:2
                        /   \      /   \
                       d     a    n     k
->+:2 ->+:2-> s:2->i:2->h:2->e:2->I:2->+:4 ->+:4 ->l:4->t:5->'':8->
                              +:4
                           /        \
                          +:2       +:2
                         /   \     /   \
                        r     o   y     u
-> s:2->i:2->h:2->e:2->I:2->+:4 ->+:4 ->+:4 ->l:4->t:5->'':8->
                              +:4
                           /        \
                          s          i
->h:2->e:2->I:2->+:4 ->+:4 ->+:4 ->+:4 ->l:4->t:5->'':8->
                              +:4
                           /        \
                          h          e
->I:2->+:4 ->+:4 ->+:4 ->+:4 ->+:4 ->l:4->t:5->'':8->
                              +:6
                           /        \
                          I         +:4
                                 /        \
                                h          e
->+:4 ->+:4 ->+:4 ->+:4 ->l:4->t:5->+:6 ->'':8->
                              +:8
                  /                         \
                +:4                         +:4
             /        \               /             \
            s          i            +:2             +:2
                                   /   \           /    \
                                  r     o         y      u
->+:4 ->+:4 ->l:4->t:5->+:6 ->+:8 ->'':8->
                              +:8
                  /                         \
                 +:4                        +:4
            /           \              /            \
          +:2           +:2          +:2            +:2
         /   \         /   \        /   \          /   \
        d     a       n     k      .     !        W     A
->l:4->t:5->+:6 ->+:8 ->+:8 ->'':8->
                                    +:9
                                   /   \
                                  l     t
-> +:6 ->+:8 ->+:8 ->'':8->+:9 ->
                                    +:14
                     /                                      \
                  +:6                                       +:8
            /              \                       /                   \
           I               +:4                    +:4                  +:4
                        /        \             /      \             /        \
                       h          e          +:2      +:2         +:2        +:2
                                            /   \    /   \       /    \     /    \
                                           d     a  n     k     .      !   W      A
->+:8 ->'':8->+:9 ->+:14 ->
                                    +:16
                           /                      \
                         +:8                      ''
               /                       \
             +:4                       +:4
         /        \                 /        \
        s          i              +:2        +:2
                                 /   \      /   \
                                r     o    y     u
->+:9 ->+:14 ->16 ->
                               +:23
               /                                  \
             +:9                                  +:14
          /       \             /                                   \
         l         t          +:6                                   +:8
                         /         \                  /                          \
                        I          +:4               +:4                         +:4
                                /        \       /          \                /          \
                              h           e    +:2          +:2           +:2           +:2
                                              /   \        /   \         /   \         /   \
                                             d     a      n     k       .     !       W     A
->+:16 ->+:23 ->
                                    +:39
                          /                         \
                        +:16                        +:23
           /                    \          /                    \
         +:8                    ''       +:9                    +:14
    /             \                     /   \         /                     \
  +:4             +:4                  l     t      +:6                     +:8
 /   \         /        \                          /   \           /                 \
s     i     +:2        +:2                        I    +:4       +:4                 +:4
           /   \      /   \                           /   \     /     \           /        \
          r     o    y     u                         h     e  +:2     +:2       +:2        +:2
                                                             /   \   /   \     /   \      /   \
                                                            d     a n     k   .     !    W     A
                                 */
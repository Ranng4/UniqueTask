//
// Created by Lenovo on 25-4-8.
//

#include"queue.h"
int main(){

  Queue queue = QueueInit();
  printf("\n");
  push(queue,1 );
  push(queue,4 );
  push(queue,132 );
  push(queue,423 );
  push(queue,42211111 );
  push(queue,52 );
  printf("%d\n",pop(queue));
  bidirectionalNodePrint(queue);
  printf("%s\n",empty(queue)?"true":"false");
  pop(queue);
  printf("%d\n",size(queue));
  printf("%d\n",back(queue));
  printf("%d\n",front(queue));


  return 0;
}

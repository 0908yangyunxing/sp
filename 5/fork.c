#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void print_george() {    // 每隔一秒鐘印出一次 George 的函數
  while (1) {    
    printf("George\n");    
    sleep(1);    
  }    
}    

void print_mary() {     // 每隔2秒鐘印出一次 Mary 的函數
  while (1) {    
    printf("Mary\n");    
    sleep(2);    
  }    
}    

int main() {     // 主程式開始
  pid_t pid1, pid2;    // 宣告兩個子程序

  pid1 = fork();     // 建立第一個子程序
  if (pid1 == 0) {    // 子程序1執行print_george
    print_george();
    exit(0);
  }

  pid2 = fork();    // 建立第二個子程序
  if (pid2 == 0) {    // 子程序2執行print_mary
    print_mary();
    exit(0);
  }

  while (1) {     // 主程式每隔一秒鐘
    printf("----------------\n");    // 就印出分隔行
    sleep(1);     // 停止一秒鐘
  }

  return 0;    
}
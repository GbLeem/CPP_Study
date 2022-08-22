//ITEM 35 : Prefer task-based programming to thread-based

#include<thread>
#include<asyncinfo.h>

int doAsyncWork();
std::thread t(doAsyncWork);
auto fut = std::async(doAsyncWork);

//task 기반 프로그래밍이 더 높은 수준의 abstract 가능

//async는 스레드 관리 부담을 라이브러리에게 넘기기
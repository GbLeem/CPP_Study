//ITEM 35 : Prefer task-based programming to thread-based

#include<thread>
#include<asyncinfo.h>

int doAsyncWork();
std::thread t(doAsyncWork);
auto fut = std::async(doAsyncWork);

//task ��� ���α׷����� �� ���� ������ abstract ����

//async�� ������ ���� �δ��� ���̺귯������ �ѱ��
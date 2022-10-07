//						<Usages>

//언제 exception을 사용해야 하는가??

//1. exception이 생기는 순간 overhead가 생긴다..
//-> for 문안에 f()함수가 exception이 생길수가 있다면 -> 사용하지 않는 것이 좋다.

//2. 함수 f()안에서 error처리가 완벽하게 가능하면 굳이 exception사용하지 않아도 된다,

//**3**. constructor는 return 타입이 존재하지 않는다.
//-> object 생성 시 에러가 발생하면 exception 말고는 에러를 전달할 방법이 없다. -> 사용하자

//4. nullptr, out of range -> exception 핸들링 사용 x

//5. 절대 일어나지 않을 일에 대한 처리


//가비지 컬렉터가 있는 언어가 아니니까... 고민을 하고 쓰자
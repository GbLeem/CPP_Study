//매개변수의 default value

//1.
//#include<iostream>
//
//int BoxVolume(int length, int width, int height)
//{
//	return length * width * height;
//}
//
//int BoxVolume(int length, int width)
//{
//	return length * width;
//}
//
//int BoxVolume(int length)
//{
//	return length;
//}
//
//int main()
//{
//	std::cout << "[3,3,3]: " << BoxVolume(3, 3, 3) << std::endl;
//	std::cout << "[5,5,D]: " << BoxVolume(5, 5) << std::endl;
//	std::cout << "[7,D,D]: " << BoxVolume(7) << std::endl;
//	//std::cout << "[D,D,D]: " << BoxVolume() << std::endl;
//	return 0;
//}

//2.
//빈칸에 아무것도 넣지 않았을때 어느 쪽의 함수를 호출할지가 문제임
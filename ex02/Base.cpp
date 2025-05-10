#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}

Base* generate(void){
	srand(time(NULL));
	int index = rand() % 3;
	switch (index)
	{
	case 1: 
		return new A;
		break;
	case 2:
		return new B;
		break;
	default:
		return new C;
		break;
	}
}

void identify(Base* p){
	if(dynamic_cast<A*>(p))
		std::cout << "Type : A" <<std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "Type : B" <<std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "Type : C" <<std::endl;
}

void identify(Base& p){
	try{
		(void)dynamic_cast<A&>(p);
		std::cout << "Type : A" <<std::endl;
		return ;
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try{
		(void)dynamic_cast<B&>(p);
		std::cout << "Type : B" <<std::endl;
		return ;
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try{
		(void)dynamic_cast<C&>(p);
		std::cout << "Type : C" <<std::endl;
		return ;
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
}
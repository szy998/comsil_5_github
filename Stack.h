#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. tack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//1. Must extend to template class
//2. The Delete function must be redefined in stack format
//Note: first, current_size are member variables of class, so this pointer must be used to import

//LinkedList class를 상속받음
template<class T>
class Stack : public LinkedList<T> {
	public:
		bool Delete (T &element) {

			//first가 0이면 false반환
			if (this->current_size == 0)
				return false;
			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제

			Node<T>* t = this->first;
			element = this->first->data;
			--this->current_size;
			this->first = this->first->link;
			delete t;
			t=NULL;
			//when we free/delate a pointer, we can set it to NULL, it can avoid wild pointer.
			return true;

		}
};

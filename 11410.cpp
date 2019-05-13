#include<cstddef>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<string>
//-----------------------------------------
#include<cstddef>
#include<iosfwd>

namespace oj
{
	typedef int data_t;

	class Vector
	{
		data_t *begin_;	//begin of array
		data_t *end_;	//end of array
		data_t *last_;	//end of current element
	public:
		Vector();
		
		std::size_t capacity() const;
		std::size_t size() const;
		
		//ignore the keyword "inline"
		//operator[] makes Vector like a C-array, for example
		//int a[2]{2,1};
		//Vector vec;
		//vec.push_back(1);
		//vec.push_back(2);
		//vec[0] is equal to a[1]
		//vec[1] is equal to a[0]
		inline data_t& operator[](const std::size_t pos)
		{
			return begin_[pos];
		}
		inline const data_t& operator[](const std::size_t pos) const
		{
			return begin_[pos];
		}
		
		void pop_back();
		void push_back(data_t val);
		void insert(std::size_t pos,std::size_t count,data_t val);
		
		void reserve(std::size_t new_capacity);
		void resize(std::size_t new_size);
		
		~Vector();
	};

	std::ostream& operator<<(std::ostream &os,const Vector &vec);	//for cout
}

//-----------------------------------------
//constructor, push_back(), pop_back(), capacity(), size(), reserve(), resize(), insert() and destructor
#include<iostream>
#include<cstddef>
#include<iosfwd>
using namespace std;
namespace oj{
    
    Vector::Vector(){
        begin_ = end_ = last_ = NULL;
    }
    Vector::~Vector(){
        delete []begin_;
    }
    void Vector::pop_back(){
        if(this->size() != 0)
            last_--;
        return ;
    }
    void Vector::push_back(data_t val){
        if(size() == capacity()){
            reserve(max(capacity()+1, capacity()*3));
        }
        *last_ = val;
        last_++;
        return ;
    }
    void Vector::insert(size_t pos,size_t count,data_t val){
        size_t original_size = this->size();
        if(count + size() > capacity()){
            reserve(max(capacity() + capacity()/2 , capacity() + count));
        }
        //start moving data;
        std::copy_backward(begin_+pos, last_, last_+count);
        std::fill(begin_+pos, begin_+pos+count, val);
        last_ += count;
    }
    size_t Vector::capacity() const{
        return end_ - begin_;
    }
    size_t Vector::size() const{
        return last_ - begin_;
    }
    void Vector::reserve(size_t new_capacity){
        if(new_capacity > capacity()){
            size_t original_size = this->size();
            data_t *new_begin_ = new data_t[new_capacity];
            std::copy(begin_, last_, new_begin_);
            delete []begin_;
            begin_ = new_begin_;
            last_ = begin_ + original_size;
            end_ = begin_ + new_capacity;
        }
        return ;
    }
    void Vector::resize(size_t new_size){
        if(new_size > capacity()){
            size_t original_size = size();
            reserve(new_size);
            std::fill(begin_ + original_size, begin_ + new_size, 0);
        }
        else if(new_size > size()){
            std::fill(begin_ + size(), begin_ + new_size, 0);
            
        }
        //if(newsize < size())
        last_ = begin_ + new_size;
        return;
    }
}
//-----------------------------------------
#include<cstdlib>
#include<iostream>
#include<string>

namespace oj
{
	std::ostream& operator<<(std::ostream &os,const Vector &vec)
	{
		for(std::size_t i(0);i!=vec.size();++i)
			os<<vec[i]<<' ';
		return os;
	}
}

int main()
{
	using namespace std;
	{
		oj::Vector v;
		string command;

		for(oj::data_t n;cin>>command;)
		{
			if(command=="pop_back")
			{
				v.pop_back();
				cout<<v<<endl;
			}
			else if(command=="push_back")
			{
				cin>>n;
				v.push_back(n);
				cout<<v<<endl;
			}
			else if(command=="insert")
			{
				size_t pos,count;
				cin>>pos>>count>>n;
				v.insert(pos,count,n);
				cout<<v<<endl;
			}
			else if(command=="capacity")
				cout<<v.capacity()<<endl;
			else if(command=="size")
				cout<<v.size()<<endl;
			else if(command=="reserve")
			{
				cin>>n;
				v.reserve(n);
				cout<<v<<endl;
			}
			else if(command=="resize")
			{
				cin>>n;
				v.resize(n);
				cout<<v<<endl;
			}
		}
		cout<<v<<endl;
	}
}
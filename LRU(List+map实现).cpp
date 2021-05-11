#include<iostream>
#include<list>
#include<map>
using namespace std;

#if 0
struct MyLRUnode
{
	int key;//形成key+value结构
	int value;
	MyLRUnode(int a, int b) :key(a), value(b){}
};
class LRUCache
{
public:
	LRUCache(int size)
	{
		Lru_capacity = size;
	}
	int get(int key)
	{
		if (mymap.find(key) != mymap.end())
		{
			mylist.splice(mylist.begin(), mylist, mymap[key]);//则将mylist链表上找到的的iterator位置的元素重新链接到mylist.begin()位置上
			mymap[key] = mylist.begin();//然后将map映射表中 键为key的页面映射位置重置一下
			return mymap[key]->value;//最后返回将key对应的value返回
		}
		else
		{
			return -1;
		}
	}

	void put(int key,int value)
	{
		if (mymap.find(key) == mymap.end())//key值不在页中
		{
			if (mylist.size() == Lru_capacity)//不在页中并且页还满了
			{
				mymap.erase(mylist.back().key);//将list尾部节点对应的key和其页映射关系删除
				mylist.pop_back();//将list尾部节点删除
			}
			MyLRUnode pnewnode(key, value);//创建新页
			mylist.push_front(pnewnode);//插入页链表中
			mymap[key] = mylist.begin();//key对应页面关系存入map
		}
		else//key值在页中
		{
			mymap[key]->value = value;//更新key对应的value值
			mylist.splice(mylist.begin(), mylist, mymap[key]);//将mylist链表上找到的的iterator位置的元素重新链接到mylist.begin()位置上
			mymap[key] = mylist.begin();//然后将map映射表中 键为key的页面映射位置重置一下
		}
	}

	void show_list()
	{
		list<MyLRUnode>::iterator it = mylist.begin();
		for (; it != mylist.end();)
		{
			cout << it->key << ":" << it->value << endl;
			it++;
		}
		cout << endl;
	}

	void show_map()
	{
		map<int, list<MyLRUnode>::iterator>::iterator it = mymap.begin();
		while (it != mymap.end())
		{
			cout << it->first << ":" << (it->second)->value << endl;
			it++;
		}
		cout << endl;
	}
private:
	int Lru_capacity;
	list<MyLRUnode> mylist;
	map<int, list<MyLRUnode>::iterator> mymap;//用来通过key键值 直接找到对应的双向链表节点
};

int main()
{
	LRUCache lru(3);
	lru.put(1, 100);
	lru.show_list();
	lru.show_map();
	lru.put(2, 200);
	lru.show_list();
	lru.show_map();
	lru.put(3, 300);
	lru.show_list();
	lru.show_map();
	lru.get(2);
	lru.show_list();
	lru.show_map();
	lru.put(4, 400);
	lru.show_list();
	lru.show_map();
	return 0;
}
#endif
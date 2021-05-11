#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
struct MyLRUnode
{
	int key;//形成key_value结构，通过这个唯一的键 直接可以找到这个值
	int value;
	MyLRUnode(int a, int b) :key(a), value(b) {}
};

class LRUCache
{
public:
	LRUCache(int size)
	{
		Lru_capacity = size;
	}
	int get(int key) //访问键为key的页面 找到 则将其重新插入到链表头
	{
		if (myhash_map.find(key) != myhash_map.end())//如果找到了
		{
			mylist.splice(mylist.begin(), mylist, myhash_map[key]);//则将mylist链表上找到的的iterator位置的元素重新链接到mylist.begin()位置上
			myhash_map[key] = mylist.begin();//然后将map映射表中 键为key的页面映射位置重置一下
			return myhash_map[key]->value;//最后返回将key对应的value返回
		}
		else//没找到 则返回-1
		{
			return -1;
		}
	}

	void put(int key, int value)//访问key value页面是否存在，若存在则提前“并更新value值”，不存在则创建之后再提前
	{
		if (myhash_map.find(key) == myhash_map.end())//key值不在页中
		{
			if (mylist.size() == Lru_capacity)//不在页中并且页还满了
			{
				myhash_map.erase(mylist.back().key);//将list尾部节点对应的key和其页映射关系删除
				mylist.pop_back();//将list尾部节点删除
			}
			MyLRUnode pnewnode(key, value);//创建新页
			mylist.push_front(pnewnode);//插入页链表中
			myhash_map[key] = mylist.begin();//key对应页面关系存入map
		}
		else//key值在页中
		{
			myhash_map[key]->value = value;//更新key对应的value值
			mylist.splice(mylist.begin(), mylist, myhash_map[key]);//将mylist链表上找到的的iterator位置的元素重新链接到mylist.begin()位置上
			myhash_map[key] = mylist.begin();//然后将map映射表中 键为key的页面映射位置重置一下
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
		unordered_map<int, list<MyLRUnode>::iterator>::iterator it = myhash_map.begin();
		while (it != myhash_map.end())
		{
			cout << it->first << ":" << (it->second)->value << endl;
			it++;
		}
		cout << endl;
	}
private:
	int Lru_capacity;
	list<MyLRUnode> mylist;
	//map<int, list<MyLRUnode>::iterator> mymap;//用来通过key键值 直接找到对应的双向链表节点
	unordered_map<int, list<MyLRUnode>::iterator> myhash_map;
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

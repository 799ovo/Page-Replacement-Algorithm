#include<iostream>
#include<list>
#include<map>
using namespace std;

#if 0
struct MyLRUnode
{
	int key;//�γ�key+value�ṹ
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
			mylist.splice(mylist.begin(), mylist, mymap[key]);//��mylist�������ҵ��ĵ�iteratorλ�õ�Ԫ���������ӵ�mylist.begin()λ����
			mymap[key] = mylist.begin();//Ȼ��mapӳ����� ��Ϊkey��ҳ��ӳ��λ������һ��
			return mymap[key]->value;//��󷵻ؽ�key��Ӧ��value����
		}
		else
		{
			return -1;
		}
	}

	void put(int key,int value)
	{
		if (mymap.find(key) == mymap.end())//keyֵ����ҳ��
		{
			if (mylist.size() == Lru_capacity)//����ҳ�в���ҳ������
			{
				mymap.erase(mylist.back().key);//��listβ���ڵ��Ӧ��key����ҳӳ���ϵɾ��
				mylist.pop_back();//��listβ���ڵ�ɾ��
			}
			MyLRUnode pnewnode(key, value);//������ҳ
			mylist.push_front(pnewnode);//����ҳ������
			mymap[key] = mylist.begin();//key��Ӧҳ���ϵ����map
		}
		else//keyֵ��ҳ��
		{
			mymap[key]->value = value;//����key��Ӧ��valueֵ
			mylist.splice(mylist.begin(), mylist, mymap[key]);//��mylist�������ҵ��ĵ�iteratorλ�õ�Ԫ���������ӵ�mylist.begin()λ����
			mymap[key] = mylist.begin();//Ȼ��mapӳ����� ��Ϊkey��ҳ��ӳ��λ������һ��
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
	map<int, list<MyLRUnode>::iterator> mymap;//����ͨ��key��ֵ ֱ���ҵ���Ӧ��˫������ڵ�
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
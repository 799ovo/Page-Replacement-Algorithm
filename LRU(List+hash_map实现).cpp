#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
struct MyLRUnode
{
	int key;//�γ�key_value�ṹ��ͨ�����Ψһ�ļ� ֱ�ӿ����ҵ����ֵ
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
	int get(int key) //���ʼ�Ϊkey��ҳ�� �ҵ� �������²��뵽����ͷ
	{
		if (myhash_map.find(key) != myhash_map.end())//����ҵ���
		{
			mylist.splice(mylist.begin(), mylist, myhash_map[key]);//��mylist�������ҵ��ĵ�iteratorλ�õ�Ԫ���������ӵ�mylist.begin()λ����
			myhash_map[key] = mylist.begin();//Ȼ��mapӳ����� ��Ϊkey��ҳ��ӳ��λ������һ��
			return myhash_map[key]->value;//��󷵻ؽ�key��Ӧ��value����
		}
		else//û�ҵ� �򷵻�-1
		{
			return -1;
		}
	}

	void put(int key, int value)//����key valueҳ���Ƿ���ڣ�����������ǰ��������valueֵ�����������򴴽�֮������ǰ
	{
		if (myhash_map.find(key) == myhash_map.end())//keyֵ����ҳ��
		{
			if (mylist.size() == Lru_capacity)//����ҳ�в���ҳ������
			{
				myhash_map.erase(mylist.back().key);//��listβ���ڵ��Ӧ��key����ҳӳ���ϵɾ��
				mylist.pop_back();//��listβ���ڵ�ɾ��
			}
			MyLRUnode pnewnode(key, value);//������ҳ
			mylist.push_front(pnewnode);//����ҳ������
			myhash_map[key] = mylist.begin();//key��Ӧҳ���ϵ����map
		}
		else//keyֵ��ҳ��
		{
			myhash_map[key]->value = value;//����key��Ӧ��valueֵ
			mylist.splice(mylist.begin(), mylist, myhash_map[key]);//��mylist�������ҵ��ĵ�iteratorλ�õ�Ԫ���������ӵ�mylist.begin()λ����
			myhash_map[key] = mylist.begin();//Ȼ��mapӳ����� ��Ϊkey��ҳ��ӳ��λ������һ��
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
	//map<int, list<MyLRUnode>::iterator> mymap;//����ͨ��key��ֵ ֱ���ҵ���Ӧ��˫������ڵ�
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

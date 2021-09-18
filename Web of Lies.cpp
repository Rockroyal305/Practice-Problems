#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int nobles, friends, queries, query_type;
pair<int, int> query;
vector<pair<int, int>> friendships;
vector<int>vulnerable_nobles;

void erase_friendship(pair<int, int> friendship)
{
    for(int i = 0; i < friends; i++)
    {
        if(friendships[i] == friendship)
            friendships.erase(friendships.begin()+i);
    }
    return;
}

int main()

{

    cin >> nobles >> friends;
    for(int i = 0; i < friends; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        pair<int, int> temp = make_pair(temp1, temp2);
        friendships.push_back(temp);
    }
    cin >> queries;
    for(int i = 0; i < queries; i++)
    {
        cin >> query_type;
        if(query_type == 1)
        {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            pair<int, int> temp = make_pair(temp1, temp2);
            cout << "query_type_1" << endl;
            cout << "friendship: " << temp1 << " " << temp2 << endl;
            friendships.push_back(temp);
        }
        else if(query_type == 2)
        {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            pair<int, int> temp = make_pair(temp1, temp2);
            cout << "query_type_2" << endl;
            cout << "friendship: " << temp1 << " " << temp2 << endl;
            erase_friendship(temp);
        }
        else
        {
            cout << "query_type_3" << endl;
            vulnerable_nobles.push_back(0);
            while(vulnerable_nobles.size() >= 1)
            {
                for(int i = 0; i < vulnerable_nobles.size(); i++)
                {
                    int vulnerable_noble = vulnerable_nobles[i];
                    cout << vulnerable_nobles[i] << " ";
                    for(int j = 0; j < friendships.size(); j++)
                    {
                        if(friendships[j].first == vulnerable_noble ||
                           friendships[j].second == vulnerable_noble)
                            friendships.erase(friendships.begin()+j);
                    }
                    vulnerable_nobles.erase(vulnerable_nobles.begin());
                }
                cout << endl;
                friends = friendships.size();
                for(int i = 1; i <= nobles; i++)
                {
                    bool vulnerable = true;
                    for(int j = 0; j < friends; j++)
                    {
                        if(friendships[j].first == i)
                        {
                            if(i > friendships[j].second)
                            {
                                vulnerable = false;
                            }
                        }
                        else if(friendships[j].second == i)
                        {
                            if(i > friendships[j].first)
                            {
                                vulnerable = false;
                            }
                        }
                        else continue;
                    }
                    if(vulnerable)
                        vulnerable_nobles.push_back(i);
                }
            }
            friends = friendships.size();
            for(int i = 0; i < friends; i++)
            {
                cout << friendships[i].first << " " << friendships[i].second << endl;
            }
        }
        friends = friendships.size();
        cout << "friends: " << friends << endl;
    }
}

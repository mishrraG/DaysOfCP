#include <bits/stdc++.h>

using namespace std;
int n,m;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getMinEffort' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY C as parameter.
 */


typedef pair<int, int> iPair;

iPair Vizinho(iPair u, int i){
    switch(i){
        case 0:
            return make_pair(u.first,u.second+1);
            break;
        case 1:
            return make_pair(u.first,u.second-1);
            break;
        case 2:
            return make_pair(u.first+1,u.second);
            break;
        default:
            return make_pair(u.first-1,u.second);
            break;
    }

}

bool isValid(iPair v){
    if(v.first<0 || v.second<0 || v.first >= n || v.second>= m)
        return false;
    return true;
}


int getMinEffort(vector<vector<int> > C) {
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    vector< vector<int> > dist(n, vector<int>(m,INT_MAX));
    pq.push(make_pair(0, 0));
    dist[0][0] = 0;
    while (!pq.empty())
    {
        iPair u = pq.top();
        pq.pop();

        for(int i = 0; i < 4; ++i)
        {
            iPair v(Vizinho(u,i));
            if(isValid(v)){
                int Distancia = abs(C[u.first][u.second] - C[v.first][v.second]);
                if (dist[v.first][v.second] > max(dist[u.first][u.second],Distancia)){
                    dist[v.first][v.second] = max(dist[u.first][u.second],Distancia);
                    pq.push(v);
                }
            }
        }
    }
    return dist[n-1][m-1];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    n = stoi(first_multiple_input[0]);

    m = stoi(first_multiple_input[1]);

    vector<vector<int>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].resize(m);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < m; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }

    int answer = getMinEffort(arr);

    fout << answer << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

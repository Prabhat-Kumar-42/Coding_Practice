#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;

void createGraph(map<string, vector<string>> &dict,
                 map<string, vector<string>> &transpose,
                 string str)
{
    string Word, key;
    stringstream ss(str);
    
    int first_word = 1;
    
    while(ss >> Word)
    {
        if(first_word)
        {
            key = Word;
            first_word = 0;
            dict[key];
            continue;
        }
        dict[key].push_back(Word);
        transpose[Word].push_back(key);
    }
}

void kosarajuSCC(map<string, vector<string>> &dict,
                map<string, int> &visited, stack<string> &stk, 
                string current_node)
{
    visited[current_node] = 1;
    
    for(auto i = dict[current_node].begin(); i != dict[current_node].end(); i++)
    {
        if(!visited[*i])
        {
            kosarajuSCC(dict, visited, stk, *i);
        }
    }
    stk.push(current_node);
}


void getSCC(map<string, vector<string>> &transpose, map<string, int> &visited,
            vector<string> &SCC, string current_node)
{
    visited[current_node] = 1;
    SCC.push_back(current_node);
    
    for(auto i = transpose[current_node].begin(); i != transpose[current_node].end(); i++)
    {
        if(!visited[*i])
        {
            getSCC(transpose, visited, SCC, *i);
        }
    }
}    


// void printResult(vector<vector<string>> &result)
// {
//     vector<string>* res = NULL;
    
//     for(int i = 0; i < result.size(); i++)
//     {
//         if(result[i].size() > 1)
//         {
//             if(res == NULL)
//             {
//                 res = &result[i];
//             }
//             else if(result[i].size() < (*res).size())
//             {
//                 res = &result[i];
//             }
//         }
//     }
    
//     sort((*res).begin(), (*res).end());
    
//     cout<<(*res).size()<<'\n';
//     for(int i = 0; i < (*res).size(); i++)
//     {
//         cout<<(*res)[i];
//         if(i < (*res).size() - 1)
//         {
//             cout<<' ';
//         }
//     }
// }

void printResult(vector<vector<string>> &result)
{
    vector<string> res;
    for(int i = 0; i < result.size(); i++)
    {
        if(result[i].size() > 1)
        {
            res.insert(res.end(), result[i].begin(), result[i].end());
        }
    }
    
    sort(res.begin(), res.end());
    cout<<res.size()<<'\n';
    for(int i = 0; i < res.size(); i++)
    {
        cout<<res[i];
        if(i < res.size() - 1)
        {
            cout<<' ';
        }
    }
}

int main()
{
    int n;
    cin>>n;
    if(!n)
    {
        return 0;
    }
    
    
    map<string, vector<string>> dict, transpose;
    map<string, int> visited;
    stack<string> stk;
    
    vector<vector<string>> result;
    vector<string> SCC;
    
    while(true)
    {
        getchar();
        while(n--)
        {
            string str;
            getline(cin, str);
            createGraph(dict, transpose, str); // create graph and it's transpose
        }
        
        //Kosaraju_Algo Start here
        for(auto i = dict.begin(); i != dict.end(); i++)
        {
            string current_node = i->first;
            if(!visited[current_node])
            {
                kosarajuSCC(dict, visited, stk, current_node);
            }
        }
        
        visited.clear();        
        while(!stk.empty())
        {
            if(visited[stk.top()])
            {
                stk.pop();
                continue;
            }
            
            getSCC(transpose, visited, SCC, stk.top());
            stk.pop();
            result.push_back(SCC);
            SCC.clear();
        }
        //Kosaraju_Algo End here
        
        printResult(result);
        cout<<'\n';

        dict.clear();
        transpose.clear();
        visited.clear();
        result.clear();
        
        cin>>n;
    
        if(!n)
        {
            break;
        }
    }
}

// 6
// a b
// b c
// c a e
// e f
// f g
// g e
// 0

// 6
// a b c e f g


// 4
// a b
// b a
// c d
// d c
// 0

// 4
// a b c d

// 13
// yzkg vcjqig 
// wsd w lzjshhp omol 
// w wsd urhfyb atde lzjshhp unqqc urhfyb 
// urhfyb wsd vcjqig nupe nupe 
// lzjshhp wsd gkh ygjd wsd ygjd 
// atde qyy vcjqig omol urhfyb ygjd 
// nupe wsd atde 
// vcjqig unqqc unqqc qyy wsd urhfyb yzkg 
// ygjd lzjshhp omol atde lzjshhp wsd nupe 
// qyy wsd omol atde w 
// gkh nupe unqqc urhfyb vcjqig lzjshhp atde 
// unqqc ygjd lzjshhp 
// omol vcjqig 
// 11
// euzrg ilnt q lfmlpj 
// vcs lfmlpj 
// aielg xacto t 
// q vzkpwai ilnt 
// vzkpwai ldgny 
// xacto vzkpwai 
// zxfh q euzrg t 
// ilnt xacto 
// lfmlpj q vzkpwai 
// ldgny zxfh lfmlpj aielg 
// t euzrg xacto euzrg zxfh 
// 6
// gaxw cm kx ovxnwit 
// ovxnwit gaxw gaxw 
// zfpvtiy gaxw bch 
// cm kx zfpvtiy zfpvtiy 
// bch gaxw gaxw 
// kx ovxnwit bch gaxw 
// 3
// h vl 
// vl jdqig 
// jdqig vl 
// 5
// apa tvrrct 
// fir lyaj eaxpf 
// tvrrct apa eaxpf 
// lyaj tvrrct 
// eaxpf apa 
// 16
// zerjobh inwppwu njbc 
// xamjdn idzmr sxdc xxh 
// njbc pe xxh pe 
// idzmr hb ya zerjobh xamjdn ij xxh sobk g 
// kwoewkd hb gpp 
// sxdc g pe inwppwu njbc xxh 
// gpp inwppwu 
// ya xamjdn zerjobh ij idzmr inwppwu gpp gpp 
// pe g sobk kwoewkd ya idzmr xamjdn sobk g 
// hb xamjdn g kwoewkd sxdc xamjdn 
// inwppwu gpp kwoewkd pe idzmr ij xamjdn g 
// z sxdc sxdc g ij xamjdn 
// sobk zerjobh inwppwu ij zerjobh idzmr 
// g njbc kwoewkd ya njbc ya sobk sxdc inwppwu 
// xxh kwoewkd gpp g z gpp 
// ij xamjdn gpp inwppwu inwppwu inwppwu 
// 21
// ydenvz q dwvfcfk q ajisxdk gpi dwvfcfk gecbyf zrml 
// zrml ggvz khdjq n 
// ajisxdk zrml ufwczaf n ukdrcnj dwvfcfk mwe ufwczaf rlgmvfx sayif 
// ukdrcnj g 
// ggvz mbapnqs gpi mwe rlgmvfx 
// p n ajisxdk khdjq snv mwe zrml mbapnqs 
// khdjq sqrkihw snv sayif gpi ajisxdk q mwe gecbyf dwvfcfk 
// gpi mbapnqs dwvfcfk b dwvfcfk rlgmvfx 
// b rlgmvfx g rlgmvfx ydenvz sqrkihw 
// gecbyf n p g ufwczaf ggvz sqrkihw ydenvz snv ajisxdk 
// sayif ajisxdk gpi gecbyf n gpi mwe ufwczaf rlgmvfx ydenvz mwe 
// q snv khdjq ukdrcnj b ydenvz g 
// mwe dwvfcfk dwvfcfk sayif ggvz ufwczaf gpi 
// mbapnqs ydenvz 
// dwvfcfk rlgmvfx n zrml rlgmvfx 
// g gpi 
// rlgmvfx g p sayif ydenvz g zrml 
// ufwczaf sqrkihw sayif p gpi mbapnqs p 
// sqrkihw gpi b sayif gpi n mwe ajisxdk mbapnqs 
// snv n g ggvz mbapnqs rlgmvfx sayif zrml q 
// n snv p sayif mbapnqs ukdrcnj sayif ufwczaf sayif sayif mwe 
// 0

// 13
// atde gkh lzjshhp nupe omol qyy unqqc urhfyb vcjqig w wsd ygjd yzkg
// 10
// aielg euzrg ilnt ldgny lfmlpj q t vzkpwai xacto zxfh
// 6
// bch cm gaxw kx ovxnwit zfpvtiy
// 2
// jdqig vl
// 3
// apa eaxpf tvrrct
// 16
// g gpp hb idzmr ij inwppwu kwoewkd njbc pe sobk sxdc xamjdn xxh ya z zerjobh
// 21
// ajisxdk b dwvfcfk g gecbyf ggvz gpi khdjq mbapnqs mwe n p q rlgmvfx sayif snv sqrkihw ufwczaf ukdrcnj ydenvz zrml

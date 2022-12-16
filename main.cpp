#include<iostream>
#include<fstream>
#include<vector>
#include<array>
#include<string>

using namespace std;

const int zabava[]={29700,33250,32000,6700};
const string trajanjeZabave="43:08:11";

vector<string> split(string s,char del){
    int i=0,j=0;
    vector<string> res;
    while(true){
        j=s.find_first_of(del,j);
        if(j==-1){
            res.push_back(s.substr(i,s.length()-i));
            break;
        }
        res.push_back(s.substr(i,j-i));
        i=++j;
    }
    return res;
}

double toHours(string trajanje){
    vector<string> exploded=split(trajanje,':');
    return stod(exploded[0])+stod(exploded[1])/60+stod(exploded[2])/3600;
}

const double trajanje=toHours(trajanjeZabave);

int main(){
    int i,j,ukupnaProd=0,t;
    string line;
    ifstream fin;
    ofstream fout;
    vector<int> turaPoSatu, ukupno={0,0,0,0};
    vector<array<int,4>> prod;
    vector<string> vline,name;

    fin.open("produkcija");
    fout.open("rezultat");

    while(getline(fin,line)){
        if(line=="")
            continue;
        vline=split(line,' ');
        name.push_back(vline[0]);
            prod.push_back({0,0,0,0});
        for(i=0;i<4;i++)
            prod.back()[i]=stoi(vline[i+1]);
        turaPoSatu.push_back(stoi(vline.back()));
    }

    for(i=0;i<prod.size();i++){
        fout<<name[i]<<" ";
        for(j=0;j<4;j++){
            t=int((prod[i][j]-zabava[j]/trajanje)/turaPoSatu[i])-(j==3?12/turaPoSatu[i]:0);
            fout<<t<<" ";
            ukupno[j]+=t*turaPoSatu[i];
            ukupnaProd+=prod[i][j];
        }
        fout<<endl;
    }
    fout<<"\n Proizvodnja naloga: "<<ukupnaProd<<endl;
    fout<<"\n Salje se: ";
    for(i=0;i<4;i++)
        fout<<ukupno[i]<<" ";
    fout<<"po satu"<<endl;
    return 0;
}
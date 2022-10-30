#include<bits/stdc++.h>
using namespace std;

// function for converting int to binary
string intToBin(int x){
	string ans = "";
	while(x){
		if(x%2 == 0) ans+="0";
		else ans+="1";

		x/=2;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	string s;
	cout<<"Enter binary input: ";
	cin>>s;
	int n = s.size();

	map<string, int>index;
	index["0"] = 1;
	index["1"] = 2;
	string t="";
	int k=0, j=3; // s er index, seq er index

	while(1){
		if(k==n) break;

		t="";
		t=+s[k], k++;

		while(k<n and index[t]>0){ // already map e thakle add korte thakbo
			t+=s[k];
			k++;
		}
		if(index[t]>0 and k==n) break;
		index[t] = j, j++;
	}
	 for(auto t: index) cout<<t.first<<" "<<t.second<<endl;

    // ekhon every sequence er last char ta baad dia baki parttuku koi ache seta ber kora lagbe
    // ar setar binary ber kore last char ta add kore block e rakha lagbe!

	int totalBlocks = index.size();
	string blocks[totalBlocks+1]; // 1-based

	for(auto t: index){
		string seq = t.first;
		int seqIndex = t.second;
		int seqSize = seq.size();
		string prefix = "";
		for(int i=0; i<seqSize-1; i++){
			prefix+=seq[i];
		}

		int indexNum = index[prefix]; // last er char baad dia bakituku koto index e ache
		string binaryForm = intToBin(indexNum);

		binaryForm += seq[seqSize-1];
		blocks[seqIndex] = binaryForm;

//		// making 4 bits
//		string zeros = "";
//		if(binaryForm.size() < 4){
//			int need0 = 4-binaryForm.size();
//			for(int i=0; i<need0; i++){
//				zeros+="0";
//			}
//		}
	}

	// making equal bits
	int maxSize = 0;
	for(int i=1; i<totalBlocks+1; i++){
		int blockSize = blocks[i].size();
		maxSize = max(maxSize, blockSize);
	}

	for(int i=1; i<totalBlocks+1; i++){
		int blockSize = blocks[i].size();
		if(blockSize < maxSize){
			string zeros = "";
			int need0 = maxSize-blockSize;
			for(int i=0; i<need0; i++){
				zeros+="0";
			}
			blocks[i] = zeros+blocks[i]; // replace
		}
	}

	cout<<"Binary blocks are: ";
	for(int i=1; i<totalBlocks+1; i++){
		cout<<blocks[i]<<" ";
	}
}

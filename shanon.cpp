//Shannon Fano Algorithm 
//Roll no 32255
#include <bits/stdc++.h> 
using namespace std; 

struct node { 
	string sym; 
	float pro; 
	int arr[20]; 
	int top; 
	int length;
} p[20]; 

typedef struct node node; 

void shannon(int l, int h, node p[]) 
{ 
	float pack1 = 0, pack2 = 0, diff1 = 0, diff2 = 0; 
	int i, d, k, j; 
	if ((l + 1) == h || l == h || l > h) { 
		if (l == h || l > h) 
			return; 
		p[h].arr[++(p[h].top)] = 0; 
		p[l].arr[++(p[l].top)] = 1; 
		return; 
	} 
	else { 
		for (i = l; i <= h - 1; i++) 
			pack1 = pack1 + p[i].pro; 
		pack2 = pack2 + p[h].pro; 
		diff1 = pack1 - pack2; 
		if (diff1 < 0) 
			diff1 = diff1 * -1; 
		j = 2; 
		while (j != h - l + 1) { 
			k = h - j; 
			pack1 = pack2 = 0; 
			for (i = l; i <= k; i++) 
				pack1 = pack1 + p[i].pro; 
			for (i = h; i > k; i--) 
				pack2 = pack2 + p[i].pro; 
			diff2 = pack1 - pack2; 
			if (diff2 < 0) 
				diff2 = diff2 * -1; 
			if (diff2 >= diff1) 
				break; 
			diff1 = diff2; 
			j++; 
		} 
		k++; 
		for (i = l; i <= k; i++) 
			p[i].arr[++(p[i].top)] = 1; 
		for (i = k + 1; i <= h; i++) 
			p[i].arr[++(p[i].top)] = 0; 
		shannon(l, k, p); 
		shannon(k + 1, h, p); 
	} 
} 

void sortByProbability(int n, node p[]) 
{ 
	int i, j; 
	node temp; 
	for (j = 1; j <= n - 1; j++) { 
		for (i = 0; i < n - 1; i++) { 
			if ((p[i].pro) > (p[i + 1].pro)) { 
				temp.pro = p[i].pro; 
				temp.sym = p[i].sym; 

				p[i].pro = p[i + 1].pro; 
				p[i].sym = p[i + 1].sym; 

				p[i + 1].pro = temp.pro; 
				p[i + 1].sym = temp.sym; 
			} 
		} 
	} 
}

void display(int n, node p[]) 
{ 
	int i, j; 
	cout << "\nSymbol\tProbability\tCode"; 
	for (i = n - 1; i >= 0; i--) { 
		cout << "\n" << p[i].sym << "\t" << p[i].pro << "\t\t"; 
		for (j = 0; j <= p[i].top; j++) 
			{
				cout << p[i].arr[j]; 
				p[i].length++;
			}
	} 
} 

int main() 
{ 
	int n, i, j; 
	float total = 0; 
	string ch; 
	node temp; 

	cout << "Enter number of symbols: "; 
	cin>>n; 

	for (i = 0; i < n; i++) { 
		cout << "Enter symbol " << i + 1 << ": "; 
		cin>>ch;
		p[i].sym += ch; 
	}


	float x[n]; 
	for (i = 0; i < n; i++) { 
		cout << "Enter probability of " << p[i].sym << ": "; 
		cin>>x[i]; 
		p[i].pro = x[i]; 
		total = total + p[i].pro; 
		
		if (total > 1) { 
			cout << "\nSum of probalities must be 1"; 
			total = total - p[i].pro; 
			i--; 
		} 
	}  
	
	p[i].pro = 1 - total; 
 
	sortByProbability(n, p); 

	for (i = 0; i < n; i++) 
	{
		p[i].top = -1;
		p[i].length = 0;
	}	 

	shannon(0, n - 1, p); 

	display(n, p); 
	
	float en=0.0,lbar=0.0;
	
	for (int i=0;i<n;i++)
	{
		en=en+p[i].pro*log2(1/p[i].pro);
		lbar=lbar+p[i].pro*p[i].length;
	}
	
	cout<<"\nEntropy of DMS"<<endl;
	cout<<en<<"bits/symbol"<<endl;
	cout<<"Average Codeword Length"<<endl;
	cout<<lbar<<"bits/symbol"<<endl;
	cout<<"Code Efficiency"<<endl;
	cout<<(en/lbar)*100<<"%"<<endl;
	cout<<"Code Redundancy"<<endl;
	cout<<(1-(en/lbar))*100<<"%"<<endl;
	
	return 0; 
} 


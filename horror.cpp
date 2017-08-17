#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int main()  {
	
	int t, n, i, j, v;
	scanf("%d", &t);
	for( i=1; i<=t; i++ ) {
		vector<int> vel;
		scanf("%d", &n);
		for( j=0; j<n; j++ ) {
			scanf("%d", &v);
			vel.push_back(v);
		}
		sort( vel.begin(), vel.end() );
		printf("Case %d: %d\n", i, vel[n-1]);
	}

	return 0;
}

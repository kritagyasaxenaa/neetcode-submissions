class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        # idea is to push all zero indices and use multi source bfs
        #tuples to store pair of indices , map to store tuples if done or not
        map={}
        # list of pairs
        l=[]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]==0:
                    l.append((i,j))
        l=deque(l)
        var=0#stores the number of iterations, var//4 is the value to be pushed
        #got indices of zeros var+1/4*n
        n=len(l) #number of zeros, each zero will cause 4 iterations
        while len(l):
            v=l.popleft()
            n-=1
            if v in map:
                if n==0:
                    n=len(l)
                    var+=1
                continue
            map[v]=True
            a=v[0]
            b=v[1]
            if(a>=len(grid) or b>=len(grid[0]) or a<0 or b<0 or grid[a][b]==-1):
                if n==0:
                    n=len(l)
                    var+=1
                continue
            grid[a][b]=var
            l.append((a+1,b))
            l.append((a-1,b))
            l.append((a,b+1))
            l.append((a,b-1))
            if n==0:
                n=len(l)
                var+=1
        return

class Solution:

    def dfs(self, i:int, map:dict, q:set, par:int, m:dict):
        if i in q: 
            return False
        if i not in map:
            if len(list(map))==0:
                m[i]=True
                return True
            else:
                return False
        q.add(i)
        for a in map[i]:
            if a==par:
                continue
            else:
               if not self.dfs(a,map,q,i,m):
                return False
        q.remove(i)
        m[i]=True
        return True

    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        #detect cycle in an undirected graph
        map={}#create graph
        m={}
        for a,b in edges:
            if a not in map:
                map[a]=[b]
            else:
                map[a].append(b)
            if b not in map:
                map[b]=[a]
            else:
                map[b].append(a)
        q=set()
        if not self.dfs(0,map,q,-1,m):
            return False
        for i in range(n):
            if i not in m:
                return False
        return True
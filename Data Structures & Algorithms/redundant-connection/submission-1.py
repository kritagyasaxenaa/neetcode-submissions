class Solution:

    def dfs(self, i:int, map:dict, ret:List[int], q:set,par:int):
        if i in q:
            ret.append(i)
            return i #found cycle
        q.add(i)
        v=-1
        for a in map[i]:
            if not a==par:
                v=self.dfs(a,map,ret,q,i)
                if not v==-1:
                    break #found the node with cycle
        q.remove(i)
        if not v==-1:
            ret.append(i) # add to the cycle
        if i==v:    #completed cycle
            return -1
        return v


    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        #find cycle in the graph and return the edge last in the list simply use dfs
        #return -1 to mark the
        map={}
        ret=[]
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
        self.dfs(1,map,ret,q,-1)
        print(ret)
        m=-1
        v=-101
        val=[]
        for i in range(len(ret)-1):
            l=[ret[i],ret[i+1]]
            if l in edges:
                v=edges.index(l)
                if m<v:
                    m=v
                    val=l
            else:
                l=[ret[i+1],ret[i]]
                v=edges.index(l)
                if m<v:
                    m=v
                    val=l

        return val

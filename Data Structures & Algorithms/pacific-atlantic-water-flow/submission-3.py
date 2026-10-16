class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        #use multisource bfs, start from the edges and move up, also, keep a map to mark atlantic and pacific both
        pac_map={} #stores indices, both booleans
        atl_map={}
        pac=[] #the queue for pacific
        atl=[] #the queue for atlantic
        ret=[]
        for i in range (len(heights)):
            for j in range(len(heights[0])):
                if i==len(heights)-1 or j==len(heights[0])-1:
                    atl.append((i,j))
                if i==0 or j==0:
                    pac.append((i,j))
            #queues created reach low to high for each and mark 
        while len(pac):
            i,j=pac.pop()
            pac_map[(i,j)]=True
            if (i+1<len(heights) and heights[i+1][j]>=heights[i][j] and (i+1,j) not in pac_map):
                pac.append((i+1,j))
            if (j+1<len(heights[0]) and heights[i][j+1]>=heights[i][j] and (i,j+1) not in pac_map):
                pac.append((i,j+1))
            if (i-1>=0 and heights[i-1][j]>=heights[i][j] and (i-1,j) not in pac_map):
                pac.append((i-1,j))
            if (j-1>=0 and heights[i][j-1]>=heights[i][j] and (i,j-1) not in pac_map):
                pac.append((i,j-1))
        while len(atl):
            i,j=atl.pop()
            atl_map[(i,j)]=True
            if (i+1<len(heights) and heights[i+1][j]>=heights[i][j] and (i+1,j) not in atl_map):
                atl.append((i+1,j))
            if (j+1<len(heights[0]) and heights[i][j+1]>=heights[i][j] and (i,j+1) not in atl_map):
                atl.append((i,j+1))
            if (i-1>=0 and heights[i-1][j]>=heights[i][j] and (i-1,j) not in atl_map):
                atl.append((i-1,j))
            if (j-1>=0 and heights[i][j-1]>=heights[i][j] and (i,j-1) not in atl_map):
                atl.append((i,j-1))
        for i in range (len(heights)):
            for j in range(len(heights[0])):
                if (i,j) in atl_map and atl_map[(i,j)]==True and (i,j) in pac_map and pac_map[(i,j)]==True:
                    ret.append([i,j])
        return ret

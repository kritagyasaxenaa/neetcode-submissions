class Solution:
    def solve(self, board: List[List[str]]) -> None:
                #use multisource bfs, start from the edges and move up, also, keep a map to mark atlantic and pacific both
        atl=[] #the queue for atlantic
        for i in range (len(board)):
            for j in range(len(board[0])):
                if (i==len(board)-1 or j==len(board[0])-1 or i==0 or j==0) and board[i][j]=="O":
                    atl.append((i,j))
            #queues created reach low to high for each and mark 
        while len(atl):
            i,j=atl.pop()
            board[i][j]="T"
            if i+1<len(board) and board[i+1][j]=="O":
                atl.append((i+1,j))
            if j+1<len(board[0]) and board[i][j+1]=="O":
                atl.append((i,j+1))
            if i-1>=0 and board[i-1][j]=="O":
                atl.append((i-1,j))
            if j-1>=0 and board[i][j-1]=="O":
                atl.append((i,j-1))
        for i in range (len(board)):
            for j in range(len(board[0])):
                if board[i][j]=="O":
                    board[i][j]="X"
                elif board[i][j]=="T":
                    board[i][j]="O"

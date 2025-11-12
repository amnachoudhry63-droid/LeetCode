class Solution:
    def transpose(self, matrix):
        # Return the transposed matrix by swapping rows and columns
        return [list(row) for row in zip(*matrix)]

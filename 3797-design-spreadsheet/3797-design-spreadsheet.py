class Spreadsheet:

    def __init__(self, rows: int):
        self.cells = {}

    def setCell(self, cell: str, value: int) -> None:
        self.cells[cell] = value

    def resetCell(self, cell: str) -> None:
        if cell in self.cells:
            del self.cells[cell]

    def getValue(self, formula: str) -> int:
        idx = formula.index("+")
        left = formula[1:idx]
        right = formula[idx + 1 :]

        if left[0].isalpha():
            val_left = self.cells.get(left, 0)
        else:
            val_left = int(left)

        if right[0].isalpha():
            val_right = self.cells.get(right, 0)
        else:
            val_right = int(right)

        return val_left + val_right

package main

import (
	"fmt"
)

type ITree interface {
	Add(value int)
	Search(value int) bool
	Min() int
	Max() int
	PrintPre()
	PrintIn()
	PrintPos()
	Height() int
	Remove(value int) *BstNode
	IsBst() bool
	Size() int
}

type BstNode struct {
	left  *BstNode
	value int
	right *BstNode
}

func NewNode(value int) *BstNode {
	node := BstNode{}
	node.value = value
	return &node
}

func (bstNode *BstNode) Add(value int) {
	if value <= bstNode.value {
		if bstNode.left != nil {
			bstNode.left.Add(value)
		} else {
			bstNode.left = NewNode(value)
		}
	} else {
		if bstNode.right != nil {
			bstNode.right.Add(value)
		} else {
			bstNode.right = NewNode(value)
		}
	}
}

func (bstNode *BstNode) Search(value int) bool {
	if value == bstNode.value {
		return true
	} else if value < bstNode.value && bstNode.left != nil {
		return bstNode.left.Search(value)
	} else if value > bstNode.value && bstNode.right != nil {
		return bstNode.right.Search(value)
	} else {
		return false
	}
}

func (bstNode *BstNode) Min() int {
	if bstNode.left != nil {
		return bstNode.left.Min()
	} else {
		return bstNode.value
	}
}

func (bstNode *BstNode) Max() int {
	if bstNode.right != nil {
		return bstNode.right.Max()
	} else {
		return bstNode.value
	}
}

func (bstNode *BstNode) PrintPre() {
	fmt.Print(bstNode.value, ", ")
	if bstNode.left != nil {
		bstNode.left.PrintPre()
	}
	if bstNode.right != nil {
		bstNode.right.PrintPre()
	}
}

func (bstNode *BstNode) PrintIn() {
	if bstNode.left != nil {
		bstNode.left.PrintIn()
	}
	fmt.Print(bstNode.value, ", ")
	if bstNode.right != nil {
		bstNode.right.PrintIn()
	}
}

func (bstNode *BstNode) PrintPos() {
	if bstNode.left != nil {
		bstNode.left.PrintPos()
	}
	if bstNode.right != nil {
		bstNode.right.PrintPos()
	}
	fmt.Print(bstNode.value, ", ")
}

func (bstNode *BstNode) Height() int {
	hBasedOnLeft := 0
	hBasedOnRight := 0
	if bstNode.left != nil {
		hBasedOnLeft = 1 + bstNode.left.Height()
	}
	if bstNode.right != nil {
		hBasedOnRight = 1 + bstNode.right.Height()
	}
	if hBasedOnLeft >= hBasedOnRight {
		return hBasedOnLeft
	} else {
		return hBasedOnRight
	}
}

func (bstNode *BstNode) Remove(value int) *BstNode {
	if value < bstNode.value {
		bstNode.left = bstNode.left.Remove(value)
	} else if value > bstNode.value {
		bstNode.right = bstNode.right.Remove(value)
	} else { //encontramos o nó a ser removido
		if bstNode.left == nil && bstNode.right == nil { //caso 1: nó folha
			return nil
		} else if bstNode.left != nil && bstNode.right == nil { //caso 2: nó com 1 filho (à esquerda)
			return bstNode.left
		} else if bstNode.left == nil && bstNode.right != nil { //caso 2: nó com 1 filho (à direita)
			return bstNode.right
		} else { //caso 3: nó com 2 filhos
			maxEsq := bstNode.left.Max()
			bstNode.value = maxEsq
			bstNode.left = bstNode.left.Remove(maxEsq)
			return bstNode
		}
	}
	return bstNode
}

func (bstNode *BstNode) IsBst() bool {
	if bstNode.left != nil {
		if bstNode.value > bstNode.left.value {
			return bstNode.left.IsBst()
		} else {
			return false
		}
	}
	if bstNode.right != nil {
		if bstNode.value < bstNode.right.value {
			return bstNode.right.IsBst()
		} else {
			return false
		}
	}
	return true
}

func (bstNode *BstNode) Size() int {
	count := 1
	if bstNode.left != nil {
		count += bstNode.left.Size()
	}
	if bstNode.right != nil {
		count += bstNode.right.Size()
	}
	return count
}

/*func createBst(v []int) *BstNode{
  node := NewNode(0)
  for _, i := range v{
    node.Add(i)
  }
  return node
}*/

func main() {
	rootNode := NewNode(20)
	rootNode.Add(10)
	rootNode.Add(5)
	rootNode.Add(1)
	rootNode.Add(7)
	rootNode.Add(15)
	rootNode.Add(30)
	rootNode.Add(25)
	rootNode.Add(19)
	rootNode.Add(40)
	rootNode.Add(35)
	//            20
	//			/    \
	//		   10      30
	//		  /	\     /   \
	//		 5  15   25    40
	//		/ \     /      /
	//     1   7   19     35

	// rootNode = rootNode.Remove(20)
	// rootNode = rootNode.Remove(10)
	fmt.Println("Search 7: ", rootNode.Search(7))
	fmt.Println("Search 8: ", rootNode.Search(8))
	fmt.Println("Size: ", rootNode.Size())
	fmt.Println("Min: ", rootNode.Min())
	fmt.Println("Max: ", rootNode.Max())

	fmt.Print("Pre: ")
	rootNode.PrintPre()
	fmt.Print("\nIn: ")
	rootNode.PrintIn()
	fmt.Print("\nPos: ")
	rootNode.PrintPos()
	fmt.Println()

	fmt.Println("Height: ", rootNode.Height())
}

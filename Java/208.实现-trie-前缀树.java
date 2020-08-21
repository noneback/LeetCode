import java.util.LinkedList;

/*
 * @lc app=leetcode.cn id=208 lang=java
 *
 * [208] 实现 Trie (前缀树)
 */
// @lc code=start
class Trie {
    private LinkedList<Trie> Node = new LinkedList<>();
    private char data;
    private boolean isEnd = false;

    /** Initialize your data structure here. */
    public Trie() {

    }

    public Trie(char data) {
        this.data = data;
    }

    /** Inserts a word into the trie. */
    public void insert(String word) {
        LinkedList<Trie> tList = Node;
        for (int i = 0; i < word.length(); i++) {
            boolean isFind = false;
            for (Trie trie : tList) {
                if (trie.data == word.charAt(i)) {
                    if (i == word.length() - 1)
                        trie.isEnd = true;
                    tList = trie.Node;
                    isFind = true;
                    break;
                }
                // 第一个字符找到对应的节点
            }
            if (!isFind) {
                // 如果没找到，在现有中添加
                for (int j = i; j < word.length(); j++) {
                    Trie newOne = new Trie(word.charAt(j));
                    if (j == word.length() - 1)
                        newOne.isEnd = true;// 在末尾添加标记
                    tList.add(newOne);
                    tList = newOne.Node;

                }
                break;
            }
        }

    }

    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        LinkedList<Trie> tList = Node;
        Trie temp = null;
        for (int i = 0; i < word.length(); i++) {
            boolean isFind = false;
            for (Trie trie : tList) {
                if (trie.data == word.charAt(i)) {
                    temp = trie;
                    tList = trie.Node;
                    isFind = true;
                    break;
                }
            }
            if (!isFind)// 当前字母没找到
                return false;
        }

        return temp.isEnd;

    }

    /**
     * Returns if there is any word in the trie that starts with the given prefix.
     */
    public boolean startsWith(String prefix) {
        LinkedList<Trie> tList = Node;
        for (int i = 0; i < prefix.length(); i++) {
            boolean isFind = false;
            for (Trie trie : tList) {
                if (trie.data == prefix.charAt(i)) {
                    tList = trie.Node;
                    isFind = true;
                    break;
                }
            }
            if (!isFind)
                return false;
        }
        return true;

    }
}

/**
 * Your Trie object will be instantiated and called as such: Trie obj = new
 * Trie(); obj.insert(word); boolean param_2 = obj.search(word); boolean param_3
 * = obj.startsWith(prefix);
 */
// @lc code=end

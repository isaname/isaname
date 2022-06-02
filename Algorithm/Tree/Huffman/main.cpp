#include "HuffmanCode.h"
 
int main(int argc, const char * argv[]) {
    string str;
    
    cout << "请输入字符串进行编码：" << endl;
    cin >> str; // 输入要加密的字符串
    HuffmanCode st(str); // 对象
    cout << "对字符串编码情况如下：" << endl;
    st.Encode(); // 编码
    cout << endl;
    cout << "请输入要解码的二进制编码:" << endl;
    cin >> str;
    cout << "解码如下：" << endl;
    st.Decode(str); // 解码
    return 0;
}
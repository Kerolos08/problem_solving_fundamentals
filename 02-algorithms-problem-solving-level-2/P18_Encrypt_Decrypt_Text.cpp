#include <iostream>
#include <string>
using namespace std;

string ReadText ()
{
    string text;
    cout << "Enter the text" << endl;
    getline(cin, text);
    return text;
}

string EncryptText (string text, short EncryptionKey)
{
    int TextLengh = text.length();
    for (int i = 0; i <= TextLengh; i++)
    {
        text[i] = char((int) text[i] + EncryptionKey);
    }
    return text;
}

string DecryptText (string text, short EncryptionKey)
{
    int TextLengh = text.length();
    for (int i = 0; i <= TextLengh; i++)
    {
        text[i] = char((int) text[i] - EncryptionKey);
    }
    return text;
}

int main ()
{
    short EncryptionKey = 2;
    string TextAfterEncryption , TextAfterDecryption;
    string text = ReadText();
    TextAfterEncryption = EncryptText(text, EncryptionKey);
    TextAfterDecryption = DecryptText(TextAfterEncryption, EncryptionKey);

    cout << "\nText before encryption : " << text << endl;
    cout << "Text after encryption : " << TextAfterEncryption << endl;
    cout << "Text after decryption : " << TextAfterDecryption << endl;

}
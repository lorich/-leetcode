#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
  private:
    string dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int id = 0;
    unordered_map<string, string> m; //key is longURL, value is shortURL
    unordered_map<string, string> idm;  //key is id in DB, value is longURL
  public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        if (m.find(longUrl) != m.end())
            return m[longUrl];
        string res = "";
        id++;
        int count = id;
        while (count > 0)
        {
            res = dict[count % 62] + res;
            count /= 62;
        }
        while (res.size() < 6)
        {
            res = "0" + res;
        }
        m[longUrl] = res;
        idm[res] = longUrl;
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        if (idm.find(shortUrl) != idm.end())
            return idm[shortUrl];
        return "";
    }
};
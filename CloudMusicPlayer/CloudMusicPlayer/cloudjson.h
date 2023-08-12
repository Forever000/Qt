#ifndef CLOUDJSON_H
#define CLOUDJSON_H
#include<QString>
#include<QVector>
#include<QJsonParseError>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>

class cloudJson
{
    friend class CloudMusicPlayer;
public:
    cloudJson();
    void Init();
    void parseJson(QString json);
private:
    QVector<QString> songname_original; //歌曲名
    QVector<QString> singername;        //歌手
    QVector<QString> hashStr;           //hash
    QVector<QString> album_name;        //专辑
    QVector<int> duration;          	   //时间-总时长

    //动态数组存储歌曲的哈希编码、专辑的ID
    QVector<QString> m_Vectorlist;
    QVector<QString> m_ID;
};

#endif // CLOUDJSON_H

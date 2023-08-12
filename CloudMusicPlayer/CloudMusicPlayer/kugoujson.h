#ifndef KUGOUJSON_H
#define KUGOUJSON_H

#include<QString>
#include<QVector>
#include<QJsonParseError>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>

class kugouJson
{
    friend class CloudMusicPlayer;
public:
    kugouJson();
    void Init();
    void parseJson(QString json);
private:
    QVector<QString> songname_original; //歌曲名
    QVector<QString> singername;        //歌手
    QVector<QString> hashStr;           //hash
    QVector<QString> album_name;        //专辑
    QVector<int> duration;          	   //时间-总时长

    QVector<int> m_musicId;
};

#endif // KUGOUJSON_H

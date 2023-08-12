#include "kugoujson.h"
#include<QDebug>

kugouJson::kugouJson()
{
    Init();
}
void kugouJson::Init()
{

}
/*
 *该文件实际上是对网易云的API接口进行解析
 *
*/
void kugouJson::parseJson(QString json)
{
    qDebug()<<"kugouJson::parseJson------------------begin"<<endl;
    m_musicId.clear();
    QByteArray byte_array;
    QJsonParseError json_error;
    QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array.append(json), &json_error);
    if (json_error.error == QJsonParseError::NoError)
    {
        //与爬虫性质一样，一层一层的查找
        if (parse_doucment.isObject())
        {
            QJsonObject rootObj = parse_doucment.object();
            if (rootObj.contains("result"))
            {
                QJsonValue valuedata = rootObj.value("result");
                if (valuedata.isObject())
                {
                    QJsonObject valuedataObject = valuedata.toObject();
                    if (valuedataObject.contains("songs"))
                    {
                        QJsonValue valueArray = valuedataObject.value("songs");
                        if (valueArray.isArray())
                        {
                            QJsonArray array = valueArray.toArray();
                            int size = array.size();
                            qDebug()<<"size:"<<size;
                            for (int i = 0; i < size; i++)
                            {
                                QJsonValue value = array.at(i);
                                if (value.isObject())
                                {
                                    QJsonObject object = value.toObject();
                                    if (object.contains("id"))//id
                                    {

                                        m_musicId.append(object["id"].toInt());
                                        qDebug()<<"id0:"<<object["id"].toInt()<<endl;
                                        QJsonValue AlbumID_value = object.take("id");
                                        if (AlbumID_value.isDouble())
                                        {
//                                                m_musicId.append(AlbumID_value);
                                            QString str=QString::number(m_musicId.last());
//                                            songname_original.append(str);
//                                                AlbumID_value.toString();
                                            qDebug()<<"id:"<<str<<endl;
                                        }
                                    }
                                    if (object.contains("name"))//歌名
                                    {
                                        QJsonValue AlbumID_value = object.take("name");
                                        if (AlbumID_value.isString())
                                        {
                                            songname_original.append(AlbumID_value.toString());
                                            qDebug()<<"name:"<<AlbumID_value.toString()<<endl;
                                        }
                                    }
                                    //解析歌手名字
                                    if(object.contains("artists"))
                                    {
                                        QJsonValue valueArtists = object.value("artists");
                                        if (valueArtists.isArray())
                                        {
                                            QString artistName="";
                                            QJsonArray arrayArtists = valueArtists.toArray();
                                            for (int j = 0; j < arrayArtists.size(); j++)
                                            {
                                                QJsonValue valueName = arrayArtists[j].toObject().value("name");
                                                if (!valueName.isNull()&&valueName.isString())
                                                {
                                                    artistName+=valueName.toString()+" ";
                                                    qDebug() << "Artist name:" << valueName.toString();
                                                }
                                            }
                                            singername.append(artistName);
                                        }
                                    }

                                    //解析专辑名字
                                    if (object.contains("album"))//专辑
                                    {
                                        qDebug()<<"album1111111"<<endl;
                                        QJsonValue valueAlbum = object.value("album");
                                        if(valueAlbum.isObject())
                                        {
                                            qDebug()<<"album222"<<endl;
                                            QJsonObject arrayAlbum = valueAlbum.toObject();
                                            album_name.append(arrayAlbum.take("name").toString());
                                        }
                                    }
                                    if (object.contains("hash")) //hash
                                    {
                                        QJsonValue FileHash_value = object.take("hash");
                                        if (FileHash_value.isString())
                                        {
                                            hashStr.append(FileHash_value.toString());
                                            qDebug()<<"hashStr:"<<FileHash_value.toString()<<endl;
                                            //用Vector保存每首歌曲的hash
//                                            m_Vectorlist.append(FileHash_value.toString());
                                        }
                                    }
                                    if (object.contains("album_id"))
                                    {
                                        QJsonValue FileHash_value = object.take("album_id");
                                        if (FileHash_value.isString())
                                        {
                                            //用Vector保存每首歌曲的album_id
//                                            m_ID.append(FileHash_value.toString());
                                            qDebug()<<"FileHash_value.toString():"<<FileHash_value.toString()<<endl;
                                        }
                                    }
                                    if (object.contains("duration"))//时长
                                    {
                                       QJsonValue AlbumID_value = object.take("duration").toInt();
                                       duration.append(AlbumID_value.toInt());
                                       qDebug()<<"duration:"<<AlbumID_value.toInt()<<endl;

                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        qDebug() << json_error.errorString();
    }
    qDebug()<<"kugouJson::parseJson---------------end"<<endl;
}

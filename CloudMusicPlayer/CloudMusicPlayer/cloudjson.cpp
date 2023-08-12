#include "cloudjson.h"
#include<QDebug>



cloudJson::cloudJson()
{
    Init();
}

void cloudJson::Init()
{

}
/*
 * 该文件实际上是对酷狗的API接口进行解析
*/

void cloudJson::parseJson(QString json)
{
    qDebug()<<"cloudJson::parseJson----------------begin"<<endl;
    m_Vectorlist.clear();
    m_ID.clear();
    qDebug()<<"status_code3:"<<endl;

    QByteArray byte_array;
    QJsonParseError json_error;
    QJsonDocument parse_doucment = QJsonDocument::fromJson(byte_array.append(json), &json_error);
    if (json_error.error == QJsonParseError::NoError)
    {
        //与爬虫性质一样，一层一层的查找
        if (parse_doucment.isObject())
        {
            QJsonObject rootObj = parse_doucment.object();
            if (rootObj.contains("data"))
            {
                QJsonValue valuedata = rootObj.value("data");
                if (valuedata.isObject())
                {
                    QJsonObject valuedataObject = valuedata.toObject();
                    if (valuedataObject.contains("info"))
                    {
                        QJsonValue valueArray = valuedataObject.value("info");
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
                                    if (object.contains("songname_original"))//歌曲名
                                    {
                                        QJsonValue AlbumID_value = object.take("songname_original");
                                        if (AlbumID_value.isString())
                                        {
                                            songname_original.append(AlbumID_value.toString());
                                            qDebug()<<"songname_original:"<<AlbumID_value.toString()<<endl;
                                        }
                                    }
                                    if (object.contains("singername"))//歌手
                                    {
                                        QJsonValue AlbumID_value = object.take("singername");
                                        if (AlbumID_value.isString())
                                        {
                                            singername.append(AlbumID_value.toString());
                                            qDebug()<<"singername:"<<AlbumID_value.toString()<<endl;
                                        }
                                    }
                                    if (object.contains("album_name"))//专辑
                                    {
                                        QJsonValue AlbumID_value = object.take("album_name");
                                        if (AlbumID_value.isString())
                                        {
                                            album_name.append(AlbumID_value.toString());
                                            qDebug()<<"album_name:"<<AlbumID_value.toString()<<endl;
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
                                            m_Vectorlist.append(FileHash_value.toString());
                                        }
                                    }
                                    if (object.contains("album_id"))
                                    {
                                        QJsonValue FileHash_value = object.take("album_id");
                                        if (FileHash_value.isString())
                                        {
                                            //用Vector保存每首歌曲的album_id
                                            m_ID.append(FileHash_value.toString());
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
    qDebug()<<"cloudJson::parseJson----------------end"<<endl;
}

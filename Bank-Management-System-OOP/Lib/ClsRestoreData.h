//#pragma once
//#include <iostream>
//#include <string>
//#include <vector>
//#include <fstream>
//
//using namespace std;
//
//template <class DataType>
//class ClsRestoreData
//{
//private:
//    string _FileName;
//    static ClsRestoreData<DataType>* _Pointer;
//
//    // Constructor ÎÇÕ áãäÚ ÅäÔÇÁ ßÇÆäÇÊ ÎÇÑÌ ÇáßáÇÓ (äãØ Singleton)
//    ClsRestoreData() : _FileName("Clients.txt")
//    {
//    }
//
//    // ÊÍæíá ÇáäÕ Åáì ßÇÆä (ÇÓÊÏÚÇÁ ÏÇáÉ ÇáÊÍæíá ãä ÇáßáÇÓ ÇáããÑÑ)
//    DataType _FromString(const string& Line)
//    {
//        return DataType::ConvertLineToClientObject(Line);
//    }
//
//public:
//    // ÇáÍÕæá Úáì ÇáäÓÎÉ ÇáæÍíÏÉ ãä ÇáßáÇÓ
//    static ClsRestoreData<DataType>* Instance()
//    {
//        if (_Pointer == nullptr)
//            _Pointer = new ClsRestoreData<DataType>();
//        return _Pointer;
//    }
//
//    // ÇÓÊÚÇÏÉ ÇáÚãáÇÁ ÇáĞíä áÏíåã ÑÕíÏ ÃÚáì ãä ÍÏ ãÚíä (ÇİÊÑÇÖí 5000)
//    vector<DataType> RestoreRichClients(double Threshold = 5000)
//    {
//        vector<DataType> RichList;
//        fstream File;
//        File.open(_FileName, ios::in);
//
//        if (File.is_open())
//        {
//            string Line;
//            while (getline(File, Line))
//            {
//                if (Line == "") continue;
//
//                DataType Obj = _FromString(Line);
//
//                // İÍÕ ÇáÑÕíÏ (íÌÈ Ãä íãÊáß ÇáßÇÆä åĞå ÇáÏÇáÉ)
//                if (Obj.Get_AccountBalance() > Threshold)
//                {
//                    RichList.push_back(Obj);
//                }
//            }
//            File.close();
//        }
//        return RichList;
//    }
//
//    void SetFileName(string FileName)
//    {
//        _FileName = FileName;
//    }
//};
//
//// ÊÚÑíİ ÇáãÊÛíÑ ÇáÇÓÊÇÊíßí ÎÇÑÌ ÇáßáÇÓ (ÖÑæÑí ÌÏÇğ İí ÇáÊãÈáíÊ)
//template <class DataType>
//ClsRestoreData<DataType>* ClsRestoreData<DataType>::_Pointer = nullptr;
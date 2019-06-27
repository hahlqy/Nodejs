import xlrd
file = open("save1.json","a+",encoding="utf-8")
data = xlrd.open_workbook("test.xlsx")#excel文件名
table = data.sheet_by_name(u'Sheet1')#具体看excel中的SHEET名字
nclos = len(table.row_values(0))
nrows = table.nrows
title = list()
titles = ["来源库","题名","作者","单位","文献来源","关键词","摘要","发表时间","被引量","下载量"]
#itles= ["source_Libiary","title","author","unit","source_literature","key_words","summery","issuing_time","Cited","download"]
# for item in table.row_values(1):
#     item = item.replace("\n","")
#     item = item.replace(" ","")
#     print(item)
for item in titles:
    title.append("\""+item+"\"")
for i in range(1,nrows):
    s = "{"
    j = 0
    for item in table.row_values(i):
        if isinstance(item,str):
            item = item.replace("\t","")
            item = item.replace("\n", "")
            item = item.replace(" ", "")
            item = item.replace("\"","'")
        if j != nclos-1:
            s += title[j]+":"+"\""+str(item)+"\","
        else:
            s += title[j]+":"+"\""+str(item)+"\""
        j += 1
    s += "}"
    file.write(s+"\n")
file.close()

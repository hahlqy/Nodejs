import xlrd
file = open("save1.json","a+",encoding="utf-8")
data = xlrd.open_workbook("数据网站.xls")
table = data.sheet_by_name(u'Sheet1')
nclos = len(table.row_values(0))
nrows = table.nrows
title = list()
titles = ["Website","Link","Data","Amount","Update","type","field"]
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
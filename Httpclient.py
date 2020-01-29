import http.client

conn = http.client.HTTPSConnection("www.uci.edu")
conn.request("GET", "/")
data=conn.getresponse()

b= data.read()
s=b.decode("utf-8")
c = s.split('\n')
j=0
for i in range(0,len(c)):
	if((c[i].strip() !='') and (j<30)):
		print(c[i])
		j+=1
	

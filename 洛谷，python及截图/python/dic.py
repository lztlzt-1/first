d = {'a':24, 'g':52, 'i':12,'k':33,}
for k in sorted(d,key=d.__getitem__,reverse=True):
    print(k,d[k])
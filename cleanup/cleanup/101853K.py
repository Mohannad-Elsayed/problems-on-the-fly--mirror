for _ in range(int(input())):
    for __ in range(int(input())):
        input()
        dic = {}
        ans = ''
        for i in range(8):
            s = input().strip()
            if s.startswith('title'):
                s = s[len('title={'):]
                s = s[:-1]
                if i != 7:
                    s = s[:-1]
                dic['title'] = s.strip()

            elif s.startswith('author'):
                s = s[len('author={'):]
                s = s[:-1]
                if i != 7:
                    s = s[:-1]
                dic['author'] = s.strip()

            elif s.startswith('journal'):
                s = s[len('journal={'):]
                s = s[:-1]
                if i != 7:
                    s = s[:-1]
                dic['journal'] = s.strip()

            elif s.startswith('volume'):
                s = s[len('volume={'):]
                s = s[:-1]
                if i != 7:
                    s = s[:-1]
                dic['volume'] = s.strip()

            elif s.startswith('number'):
                s = s[len('number={'):]
                s = s[:-1]
                if i != 7:
                    s = s[:-1]
                dic['number'] = s.strip()

            elif s.startswith('pages'):
                s = s[len('pages={'):]
                s = s[:-1]
                if i != 7:
                    s = s[:-1]
                dic['pages'] = s.strip()

            elif s.startswith('year'):
                s = s[len('year={'):]
                s = s[:-1]
                if i != 7:
                    s = s[:-1]
                dic['year'] = s.strip()

            elif s.startswith('publisher'):
                s = s[len('publisher={'):]
                s = s[:-1]
                if i != 7:
                    s = s[:-1]
                dic['publisher'] = s

        input()
        
        # print(dic)
        authors = dic['author'].split(',')
        # print(authors)
        
        for a in authors:
            aa = a.split()
            ans += aa[0][0]+aa[0][1]+'. '
            ans += aa[1][0]
            if a == authors[-1]:
                ans+='. '
            else:
                ans+=', '
                
        ans += dic['title']+'. '
        ans += dic['journal']+'. '
        ans += dic['year']+';'
        # print("ans", ans+'|')
        ans += dic['volume']+'('+dic['number']+'):'
        lstp = dic['pages'].split('-')
        # print(lstp)
        ans += lstp[0].strip()+'-'+lstp[1].strip()+'.'
            
        print(ans)

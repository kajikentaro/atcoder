import sys
import urllib.request
import json
def main(argv):
    #inp = argv[0]
    inp = "hoge"
    with urllib.request.urlopen("http://challenge-server.code-check.io/api/hash/?q=" + inp ) as res:
        html = res.read().decode("utf-8")
        data = json.loads(html)
        print(data["hash"])
if __name__ == '__main__':
    main(sys.argv[1:])

import requests
import json


def getScoreboardFromApi(contests):
    url = 'https://omegaup.com/api/contest/scoreboardMerge/'
    token = '53a5fd334f14550233d86ecdc226a6c561ea03fe'
    body = {
        'contest_aliases': ','.join(contests)
    }
    header = {
        'Authorization': 'token ' + token
    }
    res = requests.get(url, params=body, headers=header)
    return json.loads(res.text)


# Get contests
with open('contests.json', 'r') as json_file:
    contests = json.load(json_file)
contests = contests['contests']

# data
data = getScoreboardFromApi(contests)


with open('score.csv', 'w', encoding='utf-8') as f:
    # Header
    f.write('Nombre,Usuario')
    for contest in contests:
        f.write(',' + contest)
    f.write(', Total\n')

    # Body
    for user in data['ranking']:
        f.write(user['name'] + ',' + user['username'])
        for contest in contests:
            f.write(',' + str(user['contests'][contest]['points']))
        f.write(',' + str(user['total']['points']) + '\n')

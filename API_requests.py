import urllib.request
import urllib.parse
import json


def load_json_data_from_url(base_url, url_params):
    url = '%s?%s' % (base_url, urllib.parse.urlencode(url_params))
    response = urllib.request.urlopen(url).read().decode('utf-8')
    return json.loads(response)


def make_tmdb_api_request(method, api_key, extra_params=None):
    extra_params = extra_params or {}
    url = 'https://api.themoviedb.org/3%s' % method
    params = {
        'api_key': api_key,
        'language': 'ru',
    }
    params.update(extra_params)
    return load_json_data_from_url(url, params)

list_of_films = []
for i in range(1000):
    string = make_tmdb_api_request(method='/movie/' + str(i+6000), api_key='4aac4d6948ada9b037fddc6466d965be')
    data = {}
    data['original_title'] = string['original_title']
    data['original_language'] = string['original_language']
    data['budget'] = string['budget']
    data['production_countries'] = string['production_countries']
    data['release_date'] = string['release_date']
    data['runtime'] = string['runtime']
    data['spoken_languages'] = string['spoken_languages']
    list_of_films.append(data)
with open('film_base.json', 'w') as inFile:
    json.dump(list_of_films, inFile, indent = 4)

    

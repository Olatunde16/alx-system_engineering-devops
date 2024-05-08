#!/usr/bin/python3
""" Function that queries Reddit API and returns the number of subscribers """
import requests


def number_of_subscribers(subreddit):
    """ Returns the total number of subscribers """
    url = f"https://www.reddit.com/r/{subreddit}/about.json"
    headers = {
        "User Agent": "linux:0x16.api.advanced:v1.0.0 (by /u/bdov_)"
    }

    try:
        response = requests.get(url, headers=headers, allow_redirects=False)
        data = response.json()
        return data['data']['subscribers']
    except (requests.exceptions.RequestException, KeyError):
        return 0

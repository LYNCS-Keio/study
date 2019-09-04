# -*- coding: utf-8 -*-

from slackbot.bot import respond_to, listen_to
import re

#test
#test
#test
#test
#test

@listen_to('ahahaha')
@respond_to('ahahaha')
def TestOfReply(message, *something):
    message.reply('ajajaja')
    #命令したユーザー名を取得
    userID = message.channel._client.users[message.body['user']][u'name']
    print userID + 'へのreply'
class Solution(object):
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        letterLogs = []
        digitLogs = []
        for log in logs:
            if log.split(" ")[1].isdigit():
                digitLogs.append(log)
            else:
                letterLogs.append(log)
        sortedLetterLogs = []

        for log in letterLogs:
            sortLog = log.split(" ")
            sortLog.append(sortLog.pop(0))
            sortLog = " ".join(sortLog)
            print(sortLog)
            if len(sortedLetterLogs) == 0:
                sortedLetterLogs.append(log)
            elif len(sortedLetterLogs) == 1:
                if sortedLetterLogs[0] < sortLog:
                    sortedLetterLogs.append(log)
                else:
                    sortedLetterLogs = [log] + sortedLetterLogs
            else:
                for i in range(len(sortedLetterLogs)):
                    if sortedLetterLogs[i] < sortLog:
                        sortedLetterLogs.insert(i, log)
                        break
        return sortedLetterLogs + digitLogs

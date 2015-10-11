import unittest
import teleinfo

class TeleInfoTest(unittest.TestCase):

	def testFrame(self):
		with open('out.txt') as f:
			teleinfo.fromFile(f)

if __name__ == '__main__':
    unittest.main()

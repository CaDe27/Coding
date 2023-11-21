#!/usr/bin/python
# -*- coding: utf-8 -*-
import logging
import sys
import os
import re
import unittest

from omegaup.validator import validatortest

class Test(unittest.TestCase):
    def test(self):
        with open('data.in', 'r') as handle:
            original_input = handle.read()

        # Aquí añade los checks necesarios de la entrada
        self.assertTrue(True)


if __name__ == '__main__':
    validatortest.main()
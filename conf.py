# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information
import os
import sys
sys.path.insert(0, os.path.abspath("."))

project = 'Casiocan 5000'
copyright = '2022, diego'
author = 'diego'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = [
    'sphinx.ext.autodoc',
    'breathe',
    'sphinxcontrib.confluencebuilder',
    'sphinxcontrib.plantuml'
]

# The file extensions of source files. Sphinx considers the files with this suffix as sources. 
# The value can be a dictionary mapping file extensions to file types. For example:
source_suffix = {
    '.rst': 'restructuredtext',
    '.md': 'markdown'
}

# The document name of the “root” document, that is, the document that contains the root toctree 
# directive. Default is 'index'.
root_doc = 'index'

# A list of paths that contain extra templates (or templates that overwrite builtin/theme-specific templates). 
# Relative paths are taken as relative to the configuration directory.
templates_path = ['Build/sphinx/_templates']

# A list of glob-style patterns [1] that are used to find source files. They are matched against the 
# source file names relative to the source directory, using slashes as directory separators on all 
# platforms. The default is **, meaning that all files are recursively included from the source directory.
#include_patterns = ['./docs']

# A list of glob-style patterns [1] that should be excluded when looking for source files. They are 
# matched against the source file names relative to the source directory, using slashes as directory 
# separators on all platforms.
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']

# This should be a dictionary in which the keys are project names and the values are paths to the folder 
# containing the doxygen output for that project.
breathe_projects = {project: "Build/doxygen/xml"}

# This should match one of the keys in the breathe_projects dictionary and indicates which project 
# should be used when the project is not specified on the directive.
breathe_default_project = project

breathe_implementation_filename_extensions = ['c', '.cc', '.cpp']

# A boolean that decides whether or not to allow publishing. This option must be explicitly set to 
# True if a user wishes to publish content. By default, the value is set to False.
confluence_publish = True
# Key of the space in Confluence to be used to publish generated documents to
confluence_space_key = 'CAS'
# The URL for the Confluence instance to publish to. The URL should be prefixed with https:// or 
# http:// (depending on the URL target). The target API folder should not be included in the URL 
# (i.e. excluding rest/api/).
confluence_server_url = 'https://modularmx.atlassian.net/wiki/'
# The username value used to authenticate with the Confluence instance. If using Confluence Cloud, 
# this value will most likely be the account’s E-mail address.
confluence_server_user = 'diego.perez@modular-mx.com'
# The password value used to authenticate with the Confluence instance. If using Confluence Cloud, 
# it is recommended to use an API token for the configured username value (see API tokens):
confluence_server_pass = 'GI9568LlOEDOGDx24aIi65B5'
# A boolean value to whether or not nest pages in a hierarchical ordered. The root of all pages is 
# typically the configured root_doc. If a root_doc instance contains a toctree, listed documents will 
# become child pages of the root_doc. This cycle continues for child pages with their own toctree markups. 
# By default, hierarchy mode is disabled with a value of False.
confluence_page_hierarchy = True


# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'alabaster'
html_static_path = ['Build/sphinx/_static']

## Welcome to your new Fab Academy site

Visit [fabacademy.org](https://fabacademy.org/) for class and other information.

* This website is built and published automatically using [GitLab CI](https://about.gitlab.com/gitlab-ci/), every time you edit the files in the docs folder
* The markdown content is generated into a site using the Mkdocs tool, a static site generator written in Python
* You can start by customizing the file `mkdocs.yml` with your information
  * To change the looks of your website, use the theme options found in the `mkdocs.yml` file or see the names of the available themes
* If you want to start a website from scratch, you can delete everything in this repository and push your own static website

## Project layout

    mkdocs.yml    # The site configuration file.
    docs/         # All site content/files should be in this folder.
        index.md  # The homepage.
        files/    # Put files you'd like available in your site here (except videos)
        images/   # You can put your images in here
        abc.md... # Other markdown pages and folders

Read more about MkDocs at [mkdocs.org](http://www.mkdocs.org).


## Building mkdocs locally

To work locally on your computer with this project, you can start with the following the steps:

> Remember to setup your SSH keys to work locally, see [GitLab Docs](https://docs.gitlab.com/ee/gitlab-basics/create-your-ssh-keys.html)

1. Clone or download this project on your computer
	* Find the clone url at the top of your projects "overview" page
	* Run `git clone git@gitlab.fabcloud.org:your/project/path.git`
1. [Install](http://www.mkdocs.org/#installation) MkDocs on your computer
1. Preview your project: `mkdocs serve`, your site can be accessed under `localhost:8000`
1. To add new pages, create the markdown file in the `docs/` folder (i.e. `touch docs/about.md`)
1. Push your changes to GitLab to automatically publish your changes
	* `git commit -m "Updated site"`
	* `git push master`


#### Git global setup

Do not forget to configure your local git environment, with same details used on Gitlab-Fabcloud.
```
git config user.name "You Name"
git config user.email "you@example.org"
```
